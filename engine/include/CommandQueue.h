//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_COMMANDQUEUE_H
#define KILLERKITTY_COMMANDQUEUE_H

#include "Command.h"

#include <queue>

namespace kke {

    template<typename T>
    class CommandQueue {
    public:
        void push(const Command<T>& command);
        Command<T> pop();
        bool isEmpty() const;
    private:
        std::queue<Command<T>> queue;
    };

    template<typename T>
    Command<T> CommandQueue<T>::pop() {
        Command<T> res = queue.back();
        queue.pop();
        return res;
    }

    template<typename T>
    bool CommandQueue<T>::isEmpty() const {
        return queue.empty();
    }

    template<typename T>
    void CommandQueue<T>::push(const Command<T>& command) {
        queue.push(command);
    }

} // kke

#endif //KILLERKITTY_COMMANDQUEUE_H
