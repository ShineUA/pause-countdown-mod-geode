#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class CountdownLayer : public geode::Popup<PauseLayer*> {
    protected:
        const CCPoint offset = CCDirector::sharedDirector()->getWinSize() / 2;
        PauseLayer* m_pLayer;
        CCLabelBMFont* m_label;
        int m_count;
        virtual bool setup(PauseLayer* pLayer) override;
        virtual void keyDown(cocos2d::enumKeyCodes key) override;
        virtual void updateLabel();
        virtual void exitLayer();
        virtual void keyBackClicked() override;
    public:
        static CountdownLayer* create(PauseLayer* pLayer);
};