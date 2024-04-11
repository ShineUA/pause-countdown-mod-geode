#include "./main.h"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "./tools/SectionSetting.hpp"
$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SectionSettingValue>("title", "none");
}

bool isResume;

#include <Geode/modify/PauseLayer.hpp>
#include "./layers/CountdownLayer.h"
class $modify(PauseLayer) {
	static void onModify(auto& self) {
		self.setHookPriority("PauseLayer::keyDown", -69420);
	}

	void onResume(CCObject* sender) {
		isResume = true;
		this->setPositionY(CCDirector::get()->getWinSize().height);
		CCScene::get()->addChild(CountdownLayer::create(this));
	}

	void keyDown(cocos2d::enumKeyCodes p0) {
		if(!isResume) {
			keyDown(p0);
		}
	}	
};

#ifndef GEODE_IS_WINDOWS

#include <Geode/modify/CCKeyboardDispatcher.hpp>
class $modify(CCKeyboardDispatcher) {
	static void onModify(auto& self) {
		self.setHookPriority("CCKeyboardDispatcher::dispatchKeyboardMSG", -69420);
	}

	bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool p2) {
		log::info("Geode windows");
		if(isResume) {
			return false;
		}
		return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, p2);
	}
};

#endif