//
// Created by Emmanuel Baah on 22.11.2023.
//

#ifndef TIMBERMAN_EVENTDISPATCHER_H
#define TIMBERMAN_EVENTDISPATCHER_H

#include "IEvent.h"
#include <queue>

namespace Game{
    namespace Events{
        /*
         * This class is responsible for dispatching events in this game
         * to their appropriate handlers
         * */
        class EventDispatcher{
        public:
            /*
             * This method is responsible for triggering new events into the event system.
             * */
            void TriggerEvent(IEvent *event);

            /*
             * This method is responsible for registering event handlers into the event system.
             * */
            void RegisterSubscriber(std::function<void(const IEvent&)>subscriber);
        private:
            std::queue<std::shared_ptr<IEvent>> m_events;
        };
    }
}
#endif //TIMBERMAN_EVENTDISPATCHER_H
