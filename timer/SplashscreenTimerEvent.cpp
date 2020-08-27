
#include "timer/SplashscreenTimerEvent.h"

#include "app.h"

using namespace dermair;

SplashscreenTimerEvent::SplashscreenTimerEvent(uint32_t milliseconds) :
    m_state(STARTUP),
    m_milliseconds(milliseconds)
{
    //
}

void
SplashscreenTimerEvent::run()
{
    switch (m_state) {
        case STARTUP:
        {
            m_state = IDLE;
            break;
        }
        
        case IDLE:
        {
            m_state = INIT_COMPONENTS;
            break;
        }

        case INIT_COMPONENTS:
        {
            splash_label_set_text("Initialize Components");
            splash_bar_set_value(33, 400);
            m_state = CONNECT_TO_TEC_CONTROLLER;
            break;
        }

        case CONNECT_TO_TEC_CONTROLLER:
        {
            splash_label_set_text("Connect to TEC Controller");
            splash_bar_set_value(66, 400);
            m_state = SYNCHRONISATION;
            break;
        }

        case SYNCHRONISATION:
        {
            splash_label_set_text("Synchronisation");
            splash_bar_set_value(100, 400);
            m_state = FINISH;
            break;
        }

        case FINISH:
        {
            splash_label_set_text("");
            splash_button_show();
            m_state = SWITCH_TO_MAIN;
            break;
        }

        case SWITCH_TO_MAIN:
        {
            app_show();
            break;
        }
    }
}
