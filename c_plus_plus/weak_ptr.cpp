//weak_ptr
// has no ownership and does not take part in the decision of when to delete a shared pointer.
#include<iostream>
#include<memory>
using namespace std;
// Has shared ownership
class Dog
{
    string m_name;
    weak_ptr<Dog> m_friend; // No ownership
public:
    Dog():m_name("nameless")
    {
        cout<<"Default "<<__func__<<endl;
    }

    Dog(string name):m_name(name)
    {
        cout<<__func__<<endl;
    }
    ~Dog()
    {
        cout<<m_name<<__func__<<endl;
    }
    void bark()
    {
        cout<<__func__<<" "<<m_name<<" Bark ... "<<endl;
    }
    void makeFriend(shared_ptr<Dog> friend_p)
    {
        m_friend = friend_p;
        cout<<"Now "<<m_name<<" and "<<friend_p->m_name<<" are friends"<<endl;
    }
    void showFriend()
    {
        cout<<"Friend of "<<m_name<<" is "<<m_friend.lock()->m_name<<endl;
    }
};

int main()
{
    shared_ptr<Dog> p1 = make_shared<Dog>("Smokey");
    shared_ptr<Dog> p2 = make_shared<Dog>("Gunner");
    p1->makeFriend(p2);
    p2->makeFriend(p1);

    p1->showFriend();
    return 0;
}
