#include "CountdownLayer.h"
#include "../main.h"
#include <Geode/modify/PauseLayer.hpp>

CountdownLayer* CountdownLayer::create(PauseLayer* pLayer) {
    CountdownLayer* ret = new CountdownLayer();
    if (ret && ret->init(0, 0, pLayer)) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool CountdownLayer::setup(PauseLayer* pLayer) {
    this->setID("countdown-layer"_spr);
    this->setZOrder(12);
    this->m_pLayer = pLayer;
    this->m_count = Mod::get()->getSettingValue<int64_t>("seconds");
    this->m_bgSprite->setVisible(false);
    this->m_closeBtn->setVisible(false);

    // pause_layer->onResume(sender);

    this->m_label = CCLabelBMFont::create(std::to_string(this->m_count).c_str(), "goldFont.fnt");
    this->m_label->setPosition(offset);

    this->m_mainLayer->addChild(this->m_label);
    this->m_label->runAction(CCSequence::create(
        CCFadeIn::create(0.2),
        nullptr
    ));
#ifdef GEODE_IS_MACOS
    this->m_label->runAction(CCRepeatForever::create(CCSequence::create(
        CCScaleTo::create(1, 1.625f),
        CCCallFunc::create(this, callfunc_selector(CountdownLayer::updateLabel)),
        nullptr
    )));
#else
    this->m_label->runAction(CCRepeatForever::create(CCSequence::create(
        CCEaseOut::create(CCScaleTo::create(1, 1.625f), 0.7),
        CCCallFunc::create(this, callfunc_selector(CountdownLayer::updateLabel)),
        nullptr
    )));    
#endif
    return true;
}

void CountdownLayer::keyDown(enumKeyCodes key) {

}

void CountdownLayer::updateLabel() {
    if(this->m_count == 0) {
        this->m_label->runAction(CCSequence::create(
            CCFadeOut::create(0.1),
            CCCallFunc::create(this, callfunc_selector(CountdownLayer::exitLayer)),
            nullptr
        ));
    } else {
        this->m_count--;
        this->m_label->setScale(1);
        this->m_label->setString(std::to_string(this->m_count).c_str());
    }
}

void CountdownLayer::exitLayer() {
    PlayLayer::get()->resume();
    this->m_pLayer->removeMeAndCleanup();
    isResume = false;
    this->onClose(nullptr);
}

void CountdownLayer::keyBackClicked() {
    
}