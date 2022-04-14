/* Main generated for Simulink Real-Time model SimpleStim */
#include <ModelInfo.hpp>
#include "SimpleStim.h"
#include "SimpleStim_calintf.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(SimpleStim_step), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 40);

/* Model descriptor */
slrealtime::ModelInfo SimpleStim_Info =
{
    "SimpleStim",
    SimpleStim_initialize,
    SimpleStim_terminate,
    []()->char const*& { return SimpleStim_M->errorStatus; },
    []()->unsigned char& { return SimpleStim_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    return slrealtime::runModel(argc, argv, SimpleStim_Info);
}
