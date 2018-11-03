//
// Created by cuizhou on 18-7-27.
//

#ifndef ALLDEMOS_LIVEQUEUE_H
#define ALLDEMOS_LIVEQUEUE_H


class LiveQueue {
public:
    LiveQueue(const int length);
    LiveQueue();
    ~LiveQueue();

    void update(float ratio);

    void gc();

private:
    void moveForward(float*);

protected:
    int _length_queue;
    int _idx=0;
    float* _queue;
};


#endif //ALLDEMOS_LIVEQUEUE_H
