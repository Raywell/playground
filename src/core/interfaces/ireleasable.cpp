#include "ireleasable.h"

IReleasable::~IReleasable() {
    destroy();
}
