#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

void display(void* pointer, string type){
    if(type == "int"){
        int* integer_pointer = static_cast<int*>(pointer);
        cout<<"DATA TYPE - Integer"<<endl;
        cout<<"VALUE - Dereferenced int value : "<<*integer_pointer<<endl;
        cout<<"ADDRESS OF VARIABLE :"<<integer_pointer<<endl;
    } 
    else if(type == "float"){
        float* float_pointer = static_cast<float*>(pointer);
        cout<<"DATA TYPE - Float"<<endl;
        cout<<"VALUE - Dereferenced int value : "<<*float_pointer<<endl;
        cout<<"ADDRESS OF VARIABLE :"<<float_pointer<<endl;
    } 
    else if(type == "string"){
        string* string_pointer = static_cast<string*>(pointer);
        cout<<"DATA TYPE - String"<<endl;
        cout<<"VALUE - Dereferenced int value : "<<*string_pointer<<endl;
        cout<<"ADDRESS OF VARIABLE :"<<string_pointer<<endl;
    }
    else{
        cout<<"Data type is not listed. Sorry! Please try again later."<<endl;
    }
}

int main(){
    int integer_variable = 100;
    float float_variable = 47.47;
    string string_variable = "Khushbu";
    void* generic_pointer = nullptr;
    int choice;
    cout<<"==================== Void Pointer Demonstration ===================="<<endl;
    cout<<"This program shows how a void pointer can point to different data types."<<endl;
    cout << "Initially, the pointer is not pointing to anything (nullptr)."<<endl;
    cout<<"This program is made by Khushbu Jain."<<endl;
    cout<<"Roll Number: 23115047"<<endl;

    while(true){
        cout<<"--------------------- Menu ---------------------"<<endl;
        cout<<"1. Point to Integer (" << integer_variable << ")"<<endl;
        cout<<"2. Point to Float (" << float_variable << ")"<<endl;
        cout<<"3. Point to String (" << string_variable << ")"<<endl;
        cout<<"4. Exit Program"<<endl;
        cout<<"Enter your choice (1/2/3/4): ";
        cin>>choice;
        switch(choice){
            case 1:
                generic_pointer = &integer_variable;
                cout<<"Setting void pointer to address of Integer variable"<<endl;
                display(generic_pointer, "int");
                cout<<endl;
                break;

            case 2:
                generic_pointer = &float_variable;
                cout<<"Setting void pointer to address of Float variable"<<endl;
                display(generic_pointer, "float");
                cout<<endl;
                break;

            case 3:
                generic_pointer = &string_variable;
                cout<<"Setting void pointer to address of String variable"<<endl;
                display(generic_pointer, "string");
                cout<<endl;
                break;    

            case 4:
                cout<<"Exiting the program!"<<endl;
                return 0;

            default:
                cout<<"ERROR! Invalid choice. Please enter 1, 2, or 3."<<endl;
        }
    }
    return 0;
}
