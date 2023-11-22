//
// Created by Emmanuel Baah on 22.11.2023.
//

#ifndef TIMBERMAN_IEVENT_H
#define TIMBERMAN_IEVENT_H
#include <string>

namespace Game{
    namespace Events{
        /*
         * This is an interface for all events in this game.
         * */
        class IEvent{
        public:
            virtual std::string GetName() const = 0;
            virtual std::string GetSource() const = 0;
            virtual std::chrono::system_clock::time_point GetTimeStamp() = 0;
        };
    }
}
#endif //TIMBERMAN_IEVENT_H
