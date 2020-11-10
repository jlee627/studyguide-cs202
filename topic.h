/*
CS202
Program 3
Written by Joshua Lee

This is the topic class header file that is responsible for keeping track 
of what topic each question belongs to. I've also overloaded the assignment
and comparison operators here to set data
*/

class topic
{
	public:
		topic();
		~topic();
		topic(char * toname);
		topic(const topic & obj);
		
		char * getTopic();
		topic& operator=(const topic & obj);
		bool operator==(const topic & obj) const;
	protected:
		char * name;
};
