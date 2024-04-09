#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class CountdownLayer : public geode::Popup<> {
    protected:
        const CCPoint offset = CCDirector::sharedDirector()->getWinSize() / 2;
        CCLabelBMFont* m_label;
        int m_count;
        virtual bool setup() override;
        virtual void keyDown(cocos2d::enumKeyCodes key) override;
        virtual void updateLabel();
        virtual void exitLayer();
    public:
        static CountdownLayer* create();
};