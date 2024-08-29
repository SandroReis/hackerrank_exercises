int getTotalX(vector<int> a, vector<int> b) {
	int max_a = a[0];
	int min_b = b[0];
	int factor_count = 0;
	for (int i = 1; i < a.size(); i++)
	{
		max_a = std::max(max_a, a[i]);
	}
	for (int i = 1; i < b.size(); i++)
	{
		min_b = std::min(min_b, b[i]);
	}

	for (int i = max_a; i <= min_b; i++) {
		bool isFactor = true;
		bool isMultiple = true;
	
		for (int ele : a) {
			if (i % ele != 0) {
				isFactor = false;
				break;
			}
		}

		for (int ele : b) {
			if (ele % i != 0)
			{
				isMultiple = false;
				break;
			}
		}
		if (isFactor && isMultiple) {
			factor_count++;
		}
	}
	return factor_count;
}
