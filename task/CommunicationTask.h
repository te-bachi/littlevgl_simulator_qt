#ifndef __COMMUNICATION_TASK_H__
#define __COMMUNICATION_TASK_H__

#include "Temperature.h"

namespace dermair {
    class CommunicationTask
    {
        private:
            bool            m_running;

        public:
                            CommunicationTask();
            virtual         ~CommunicationTask();

            void            start();
            void            run(void* data);

            void            setPowerStatus(bool status);
            Temperature     getCurrentTemperature();
            void            setTargetTemperature(Temperature temp);
    };
};

#endif
