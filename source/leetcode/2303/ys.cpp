class Solution
{
public:
	double calculateTax(vector<vector<int>> &brackets, int income)
	{
		double tax = 0.0;
		int prev_upper = 0;

		for (size_t i = 0; i < brackets.size(); ++i)
		{
			auto &bracket = brackets[i];
			int upper = bracket.front();
			double percent = bracket.back() / 100.0f;
			int diff_upper = upper - prev_upper;

			if (diff_upper > income)
			{
				tax += (income * percent);
			}
			else
			{
				tax += (diff_upper * percent);
			}

			income -= diff_upper;
			prev_upper = upper;

			if (income <= 0)
			{
				break;
			}
		}

		return tax;
	}
};
