/*

Copyright (c) 2016, PyData Development Team
All rights reserved.

Distributed under the terms of the BSD Simplified License.

The full license is in the LICENSE file, distributed with this software.

Copyright (c) 2005-2011, NumPy Developers
All rights reserved.

This file is derived from NumPy 1.7. See NUMPY_LICENSE.txt

*/

#ifndef PANDAS__LIBS_SRC_DATETIME_NP_DATETIME_H_
#define PANDAS__LIBS_SRC_DATETIME_NP_DATETIME_H_

#include <numpy/ndarraytypes.h>

typedef struct {
        npy_int64 year;
        npy_int32 month, day, hour, min, sec, us, ps, as;
} pandas_datetimestruct;

typedef struct {
        npy_int64 days;
        npy_int32 hrs, min, sec, ms, us, ns, seconds, microseconds, nanoseconds;
} pandas_timedeltastruct;

extern const pandas_datetimestruct _NS_MIN_DTS;
extern const pandas_datetimestruct _NS_MAX_DTS;

// stuff pandas needs
// ----------------------------------------------------------------------------

int convert_pydatetime_to_datetimestruct(PyObject *obj,
                                         pandas_datetimestruct *out);

npy_datetime pandas_datetimestruct_to_datetime(NPY_DATETIMEUNIT fr,
                                               pandas_datetimestruct *d);

void pandas_datetime_to_datetimestruct(npy_datetime val, NPY_DATETIMEUNIT fr,
                                       pandas_datetimestruct *result);

void pandas_timedelta_to_timedeltastruct(npy_timedelta val,
                                         NPY_DATETIMEUNIT fr,
                                         pandas_timedeltastruct *result);

int dayofweek(int y, int m, int d);

extern const int days_per_month_table[2][12];

// stuff numpy-derived code needs in header
// ----------------------------------------------------------------------------

int is_leapyear(npy_int64 year);

/*
 * Calculates the days offset from the 1970 epoch.
 */
npy_int64
get_datetimestruct_days(const pandas_datetimestruct *dts);


/*
 * Compares two pandas_datetimestruct objects chronologically
 */
int cmp_pandas_datetimestruct(const pandas_datetimestruct *a,
                              const pandas_datetimestruct *b);


/*
 * Adjusts a datetimestruct based on a minutes offset. Assumes
 * the current values are valid.
 */
void
add_minutes_to_datetimestruct(pandas_datetimestruct *dts, int minutes);


int
convert_datetime_to_datetimestruct(NPY_DATETIMEUNIT base,
                                   npy_datetime dt,
                                   pandas_datetimestruct *out);

#endif  // PANDAS__LIBS_SRC_DATETIME_NP_DATETIME_H_
