//
// Created by cuizhou on 18-7-27.
//

#include "LiveQueue.h"
LiveQueue::LiveQueue() {

}
LiveQueue::LiveQueue(const int length) {
    _length_queue=length;
    _queue = new float[length];
    _idx   = 0 ;
}

LiveQueue::~LiveQueue(){
    delete _queue;
}

void LiveQueue::update(float ratio){
    if(_idx<_length_queue){
        _queue[_idx]=ratio;
    }else{
        moveForward(_queue);
        _queue[_length_queue - 1] = ratio;
    }
    ++_idx;

}

void LiveQueue::gc(){
    _idx  = 0;
    for(int i = 0;i <_length_queue;i++)
    {
        _queue[i]=0;
    }
}
void LiveQueue::moveForward(float *frames) {
    for(int i = 1 ; i <_length_queue;i++)
    {
        frames[i-1]=frames[i];
    }
}
