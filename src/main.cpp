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
		this->exitLayer();
		CCScene::get()->addChild(CountdownLayer::create());
	}
};