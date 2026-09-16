#ifndef SHARED_PTR_HEADER
#define SHARED_PTR_HEADER

class ControlBlockBase {
public:
    ControlBlockBase(): ref_count(1) {}; // TODO: implement the default constructor.

    // dtor is virtual, so that we can call derived class's dtor from a ptr to this base class.
    virtual ~ControlBlockBase() {}; // TODO: implement the destructor.

    // pure virtual function; must be overriden by derived classes
    virtual void* managedAddress() = 0;

    // Delete copies, which also implicitly deletes moves.
    ControlBlockBase(const ControlBlockBase&) = delete;
    ControlBlockBase& operator=(const ControlBlockBase&) = delete;

    long increment()
    {
        // TODO: increment refcount by 1 and return result.
        return ++ref_count;
    }

    long decrement()
    {
        // TODO: decrement refcount by 1 and return result.
        return --ref_count;
    }

    long refCount() const
    {
        // TODO: just return the refcount.
        return ref_count;
    }

private:
    // TODO: add field(s) which both control block types need to have
    long ref_count;
};


template <typename T>
class ControlBlock : public ControlBlockBase {
public:
    ControlBlock(T* pointer) : managed_pointer(pointer) {
        // store ptr in your member field
        // managed_pointer = pointer;
    }

    ~ControlBlock() override {
        // delete the managed pointer
        delete managed_pointer;
    }

    void* managedAddress() override {
        // return the address of the managed object
        return managed_pointer;
    }

private:
    // field to hold the T*
    T* managed_pointer;
};

template <typename T>
class SharedPtr {
public:
    // default constructor

    // constructor from T*

private:
    // two fields
};
#endif
