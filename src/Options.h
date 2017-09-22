#ifndef OPTIONS_H_
#define OPTIONS_H_
#include <string>
using namespace std;
class Options
{
protected:
	int argC,count;
	char **argV;
	string optstring;
public:
    Options();
    virtual ~Options();
	void setOptstring(string validopt);
	virtual string getopt(void) = 0;
	int numopt(void);
};

#endif /* OPTIONS_H_ */
