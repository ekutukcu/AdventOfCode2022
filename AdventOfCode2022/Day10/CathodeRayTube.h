#include <unordered_set>
#include <vector>
#include <string>
class CathodeRayTube
{
private:
	int x;
	int power;
	int cycles;
	std::unordered_set<int> logPoints;
	std::string crtDisplay;

	void noop();
	void addx(int change);
	void logSignalStrength();
public:
	CathodeRayTube();
	void process(std::string instruction);
	void setLogPoint(int cycleNumber);
	int getSignalStrength();
	std::string getCrtDisplay();

	static int processStream(std::istream& inputStream, CathodeRayTube& tube);
};