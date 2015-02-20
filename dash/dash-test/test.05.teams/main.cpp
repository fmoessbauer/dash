
#include <stdio.h>
#include <iostream>
#include <libdash.h>

using namespace std;

void test_team(dash::Team& t)
{
  cout<<"Is this team TeamAll ?: "<<((t==dash::TeamAll)?"YES":"NO")<<endl;
  cout<<"Is this team TeamNull?: "<<((t==dash::TeamNull)?"YES":"NO")<<endl;

  cout<<"Size of this team:  "<<t.size()<<endl;
  cout<<"My ID in this team: "<<t.myid()<<endl;
  cout<<"This Team's position: "<<t.position()<<endl;

  if( t.parent()!=dash::TeamNull ) {
    cout<<"This team does have a parent!"<<endl;
  }

}

int main(int argc, char* argv[])
{
  dash::init(&argc, &argv);
  
  int    myid   = dash::myid();
  size_t nunits = dash::size();
  
  dash::Team& t = dash::TeamAll.split(3);
  
  test_team(t);
  
  dash::finalize();
}
