#include "SharedPtr.h"

ControlBlockBase::ControlBlockBase() {
    ref_count = 1;
}