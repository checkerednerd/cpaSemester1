/*
holds info for a contact
*/

struct Name {
	char FirstName[21];
	char lastName[21];
};

struct Job {
	char title[21];
	char company[41];
};

struct Info { //stores an instance of Name and Job
	struct Name playerName; //makes an instance of structure Name type called conName
	struct Job playerJob; //makes an instance of structure Job type called conJob
};

//declare function prototypes for doesTheThing.c
//IT NEEDS YOU!
void getName(struct Name *contactName); //Name type pointer contactName
void getJob(struct Job *contactJob); //we named the pointer contactJob, can name it anything
void clear();