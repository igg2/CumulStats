/*
CumulStats - A cumulative statistics class for any number of samples.
Based on Welford's algorithm for numerical stability.

Copyright (C) Ilya G. Goldberg

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef CUMULSTATSH
#define CUMULSTATSH

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <float.h>


#define MIN_VAL -FLT_MAX
#define MAX_VAL FLT_MAX

class CumulStats {
  private:
  	double _min, _max, _mean, M2, _var, _std;
  	size_t _n;

  public:
  	CumulStats();
	void reset();

  	double add (const double x);
  	size_t n() const;
  	double minimum() const;
  	double maximum() const;
  	double mean() const;
  	double std (); // not const, may result in computing _std
  	double var () const;
};

#endif // #ifndef CUMULSTATSH
