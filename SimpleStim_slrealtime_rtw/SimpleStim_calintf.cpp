#include "SimpleStim_calintf.h"
#include "SimpleStim.h"
#include "SimpleStim_cal.h"

extern SimpleStim_cal_type SimpleStim_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    {
      (void*)&SimpleStim_cal_impl, (void**)&SimpleStim_cal, sizeof
        (SimpleStim_cal_type), 2
    } };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
