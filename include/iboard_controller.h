#ifndef IBOARD_CONTROLLER_H
#define IBOARD_CONTROLLER_H

class IBoardController
{
public:
    virtual void Start() = 0;
    virtual ~IBoardController() = default;
};

#endif