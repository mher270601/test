int step = 1;
	int displayNext = step;
	int percent = 0;

	cout << "Processing " << totalImagesCount << " images..." << endl;

	// loop through the image count
	for (size_t i = 0; i < totalImagesCount ; ++i)
	{		
		// Individual image processing operations

                // Formatted progress indicator
		percent = (100 * (i + 1)) / totalImagesCount ;
		if (percent >= displayNext)
		{
			cout << "\r" << "[" << std::string(percent / 5, (char)254u) << std::string(100 / 5 - percent / 5, ' ') << "]";
			cout << percent << "%" << " [Image " << i + 1 << " of " << totalImagesCount << "]";
			std::cout.flush();
			displayNext += step;
		}
	}
