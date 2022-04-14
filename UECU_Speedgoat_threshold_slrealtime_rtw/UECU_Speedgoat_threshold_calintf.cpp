#include "UECU_Speedgoat_threshold_calintf.h"
#include "UECU_Speedgoat_threshold.h"
#include "UECU_Speedgoat_threshold_cal.h"

extern UECU_Speedgoat_thresho_cal_type UECU_Speedgoat_thresho_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    {
      (void*)&UECU_Speedgoat_thresho_cal_impl, (void**)
        &UECU_Speedgoat_threshold_cal, sizeof(UECU_Speedgoat_thresho_cal_type),
        2
    } };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
