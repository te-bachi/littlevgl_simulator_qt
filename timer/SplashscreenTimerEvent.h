#ifndef __SPLASHSCREEN_TIMER_EVENT_H__
#define __SPLASHSCREEN_TIMER_EVENT_H__

#include <stdint.h>

namespace dermair
{
    class SplashscreenTimerEvent
    {
        private:
            enum State {
                STARTUP,
                IDLE,
                INIT_COMPONENTS,
                CONNECT_TO_TEC_CONTROLLER,
                SYNCHRONISATION,
                FINISH
            };

            State           m_state;
            uint32_t        m_milliseconds;

        public:
                            SplashscreenTimerEvent(uint32_t milliseconds);
            virtual void    run();
    };
};

#endif
