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

#include <CumulStats.h>

CumulStats::CumulStats() {
	reset();
}

void CumulStats::reset() {
	_mean = M2 = 0.0;
	_min = _max = _var = _std = NAN;
	_n = 0;
}

double CumulStats::add (const double x) {
	size_t n1;
	double delta, delta_n, term1;
	if (isnan (x) || x > MAX_VAL || x < MIN_VAL) return (x);

	n1 = _n;
	_n = _n + 1;
	delta = x - _mean;
	delta_n = delta / _n;
	term1 = delta * delta_n * n1;
	_mean = _mean + delta_n;
	M2 += term1;
	
	if (_n == 1 || x > _max) _max = x;
	if (_n == 1 || x < _min) _min = x;
	if (_n >= 2) _var = M2/(_n - 1);
	_std = NAN;
	return (x);
}

size_t CumulStats::n()  const {
	return (_n);
}

double CumulStats::minimum()  const {
	return (_min);
}

double CumulStats::maximum()  const {
	return (_max);
}

double CumulStats::mean() const {
	return (_mean);
}

double CumulStats::std () {
	if ( isnan(_std) && !isnan(_var ) )
		_std = sqrt ( _var );
	return (_std);
}

double CumulStats::var () const {
	return (_var);
}
