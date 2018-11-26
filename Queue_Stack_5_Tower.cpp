#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);

	stack<int> tower;
	stack<int> temp;
	stack<int> result;

	int tx = 0, rx = 0;

	for (auto &it : heights)
	{
		tower.push(it);
	}

	for (int i = 0; i < heights.size(); i++)
	{
		tx = tower.top();
	
		if (tower.size() == 1)
		{
			result.push(0);
		}
		else
		{
			tower.pop();

			for (int idx = tower.size(); idx > 0; idx--)
			{
				rx = tower.top();

				if (rx > tx)
				{
					result.push(idx);

					if (!temp.empty())
					{
						for (int k = 0; k < temp.size(); k++)
						{
							tower.push(temp.top());
							temp.pop();
						}
					}

					break;
				}
				else
				{
					if (tower.size() > 1)
					{
						temp.push(rx);
						tower.pop();
					}
					else
					{
						result.push(0);
						
						if (!temp.empty())
						{
							int len = temp.size();
							for (int k = 0; k < len; k++)
							{
								tower.push(temp.top());
								temp.pop();
							}
						}
					}
				}
			}
		}
	}

	int lcnt = result.size();
	for (int i = 0; i < lcnt; i++)
	{
		answer[i] = result.top();
		result.pop();
	}

	return answer;
}