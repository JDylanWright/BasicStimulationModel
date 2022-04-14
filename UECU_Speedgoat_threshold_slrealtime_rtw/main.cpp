/* Main generated for Simulink Real-Time model UECU_Speedgoat_threshold */
#include <ModelInfo.hpp>
#include "UECU_Speedgoat_threshold.h"
#include "UECU_Speedgoat_threshold_calintf.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(UECU_Speedgoat_threshold_step), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 40);

/* Model descriptor */
slrealtime::ModelInfo UECU_Speedgoat_threshold_Info =
{
    "UECU_Speedgoat_threshold",
    UECU_Speedgoat_threshold_initialize,
    UECU_Speedgoat_threshold_terminate,
    []()->char const*& { return UECU_Speedgoat_threshold_M->errorStatus; },
    []()->unsigned char& { return UECU_Speedgoat_threshold_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    return slrealtime::runModel(argc, argv, UECU_Speedgoat_threshold_Info);
}
