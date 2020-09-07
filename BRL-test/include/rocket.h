#ifndef ROCKET_H
#define ROCKET_H

class Rocket{

private:
	int m_height;

public:
	Rocket(int height);
	void SetHeight(int height);
	void Draw(bool inversion) const;

};

#endif
