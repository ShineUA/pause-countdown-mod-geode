#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class CountdownLayer : public geode::Popup<PauseLayer*> {
    protected:
        const CCPoint offset = CCDirector::sharedDirector()->getWinSize() / 2;
        CCLabelBMFont* m_label;
        PauseLayer* m_pauseLayer;
        int m_count;
        virtual bool setup(PauseLayer* pause_layer) override;
        virtual void keyDown(cocos2d::enumKeyCodes key) override;
        virtual void updateLabel();
        virtual void exitLayer();
    public:
        static CountdownLayer* create(PauseLayer* pause_layer);
};