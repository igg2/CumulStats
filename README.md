# CumulStats
A C++ class for cumulative statistics for any number of samples using Welford's algorithm

	// Accumulate statistics without storing any samples
	CumulStats randSamples;

	for (i = 0; i < 100; i++) {
		// Generate a random sample and add it to the cumulative statistics
		long sample = random(0, 9999);
		randSamples.add(sample/100.0);

		// Statistics can be retrieved at any time during sampling
		// Number of samples so far and cumulative average
		long n_samples = randSamples.n();
		long average = randSamples.mean();

		// Minimum & maximum
		double min = randSamples.min();
		double max = randSamples.max();

		// Variance and standard deviation (unbiased, N-1)
		// N.B.: These require more than two samples (otherwise return 0.0)
		double variance = randSamples.var();
		double sigma = randSamples.std();
	}
  	
