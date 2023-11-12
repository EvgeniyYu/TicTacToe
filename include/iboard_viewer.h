#ifndef IBOARD_VIEWER_H
#define IBOARD_VIEWER_H


class IBoardViewer
{
public:
    virtual void Display() = 0;
    virtual ~IBoardViewer() = default;
};

#endif