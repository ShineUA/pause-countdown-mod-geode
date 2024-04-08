#include <Geode/Geode.hpp>
#include "./layers/CountdownLayer.h"
#include "./tools/SectionSetting.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SectionSettingValue>("title", "none");
}

#include <Geode/modify/PauseLayer.hpp>
class $modify(PauseLayer) {
	void onResume(CCObject* sender) {
		if(sender->getTag() != 50) {
			this->setVisible(false);
			CCScene::get()->addChild(CountdownLayer::create(this));
		} else {
			PauseLayer::onResume(nullptr);
		}
	}
};