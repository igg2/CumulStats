# CumulStats
A C++ class for cumulative statistics for any number of samples using Welford's algorithm

	// Accumulate statistics without storing any samples
	CumulStats randSamples;
	uint32_t i;

	for (i = 0; i < 10000; i++) {
		// Generate a random sample and add it to the cumulative statistics
		long sample = random(0, 9999);
		randSamples.add(sample/100.0);

		// Statistics can be retrieved at any time during sampling
		if (i && i % 100 == 0) {
			// Number of samples so far and cumulative average
			Serial.println (randSamples.n());
			Serial.println (randSamples.mean());

			// Minimum & maximum
			Serial.println (randSamples.minimum());
			Serial.println (randSamples.maximum());

			// Variance and standard deviation (unbiased, N-1)
			// N.B.: These require more than two samples (otherwise return 0.0)
			Serial.println (randSamples.var());
			Serial.println (randSamples.std());
			Serial.println ();
		}

		// Reset the stats and keep going
		if (i && i % 1000 == 0) {
			randSamples.reset();
			Serial.println ();
			Serial.println ();
		}
	}
