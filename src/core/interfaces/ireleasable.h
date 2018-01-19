#ifndef IRELEASABLE_H
#define IRELEASABLE_H

class IReleasable
{
public:
    virtual ~IReleasable() = 0;

    void release() { delete this; } // Use it to delete the object
protected:
    virtual void destroy() {} // Override for cleanup operations (ex. release dependent objects)
private:
};

#endif
