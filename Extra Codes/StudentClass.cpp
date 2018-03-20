
#ifndef StudentClass
#define StudentClass

class Student{
public:
    int age;
    int roll;
    ///print("Hello");
    static int totalStudents;//new

    Student(int age,int r): roll(r){//constructor man and this is initialization list

        totalStudents++;
        this->age=age;
    }

    //setters
    Student(){
        totalStudents++;
    }
    void setage(int age){

    this->age=age;
    }
    void setroll(int roll)
    {
        this->roll=roll;
    }

    void display() const
    {
        cout<<age<<" "<<roll<<endl;
    }
};

int Student::totalStudents=0;

#endif // StudentClass
