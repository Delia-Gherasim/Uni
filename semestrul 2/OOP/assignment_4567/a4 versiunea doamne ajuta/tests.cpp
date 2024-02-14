#include <cassert>
#include "DynamicVector.h"
#include "Repository.h"
#include "Service.h"
#include "tutorials.h"
//#include "tests.h"
#include <iostream>

template <typename Tutorial>
void testDynamicVector() {
    
    // Test constructor 
    DynamicVector<Tutorial> vector;
    assert(vector.getCapacity() == 100);

    // Test add() and getSize()
    Tutorial tutorial1{ "Title1", "Presenter1", "www.link1.com", 30, 15, 10 };
    Tutorial tutorial2{ "Title2", "Presenter2", "www.link2.com", 45, 30, 20 };
    vector.add(tutorial1);
    vector.add(tutorial2);
    assert(vector.getSize() == 2);
    

    // Test resize()
    DynamicVector<Tutorial> v(2); // create a vector with initial capacity of 2
    Tutorial tutorial3{ "Title3", "Presenter3", "www.link3.com", 45, 30, 20 };
    v.add(tutorial1);
    v.add(tutorial2);
    v.add(tutorial3); // should cause a resize to occur


    assert(v.getSize() == 3);


    //Test operator=
    DynamicVector<Tutorial> v1;
    v1.add(tutorial1);
    v1.add(tutorial2);
    v1.add(tutorial3);

    DynamicVector<Tutorial> v2;
    Tutorial tutorial4{ "Title4", "Presenter1", "www.link1.com", 30, 15, 10 };
    Tutorial tutorial5{ "Title5", "Presenter2", "www.link2.com", 45, 30, 20 };
    v2.add(tutorial4);
    v2.add(tutorial5);


    v2 = v1; // assign v1 to v2
    assert(v2.getElement(0).getTitle() == "Title1" && v2.getElement(1).getTitle() == "Title2" ); // elements should be equal to v1's elements


    // Test update()
    Tutorial updatedTutorial{ "Title1", "NewPresenter", "www.newlink.com", 40, 20, 15 };
    vector.update(updatedTutorial);
    assert(vector.getElement(0).getPresenter() == "NewPresenter");
    assert(vector.getElement(0).getLink() == "www.newlink.com");
    assert(vector.getElement(0).getDurationMinutes() == 40);
    assert(vector.getElement(0).getDurationSeconds() == 20);
    assert(vector.getElement(0).getNumberOfLikes() == 15);

}

void test_addTutorialService()
{
    Repository repo;
    Service service{ repo };

    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    assert(service.addTutorialService(tutorial) == 0);
    assert(service.addTutorialService(tutorial) == 1);
}

void test_deleteTutorialService()
{
    Repository repo;
    Service service{ repo };

    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    service.addTutorialService(tutorial);

    assert(service.deleteTutorialService(tutorial) == 0);
    assert(service.deleteTutorialService(tutorial) == 1);
}

void test_updateTutorialService()
{
    Repository repo;
    Service service{ repo };

    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    service.addTutorialService(tutorial);

    Tutorials newTutorial{ "newTitle", "newPresenter", "newLink", 20, 200, 20 };
    assert(service.updateTutorialService(newTutorial) == 1);

    Tutorials existingTutorial{ "title", "presenter", "newLink", 20, 200, 20 };
    assert(service.updateTutorialService(existingTutorial) == 0);
}

void test_getSize()
{
    Repository repo;
    Service service{ repo };

    assert(service.getSize() == 0);

    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    service.addTutorialService(tutorial);

    assert(service.getSize() == 1);
}

void test_getTutorialsOfAPresenter()
{
    Repository repo;
    Service service{ repo };

    Tutorials tutorial1{ "title1", "presenter1", "link1", 10, 100, 10 };
    Tutorials tutorial2{ "title2", "presenter2", "link2", 20, 200, 10 };
    Tutorials tutorial3{ "title3", "presenter1", "link3", 30, 300, 10 };

    service.addTutorialService(tutorial1);
    service.addTutorialService(tutorial2);
    service.addTutorialService(tutorial3);

    DynamicVector<Tutorials> tutorials = service.getTutorialsOfAPresenter("presenter1");

    assert(tutorials.getSize() == 2);

}
/*
void test_getRepo()
{
    Repository repo;
    Service service{ repo };

    assert(service.getRepo().getSize() == 0);

    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    service.addTutorialService(tutorial);

    assert(service.getRepo().getSize() == 1);
}
*/
void test_set_title()
{
    Repository repo;
    Service service{ repo };
    Tutorials tutorial{ "title", "presenter", "link", 10, 100, 10 };
    tutorial.setTitle("New Title");
    assert(tutorial.getTitle() == "New Title");

}
void test_get_all_tutorials() {
    Repository repo;
    Service service(repo);

    // Add some tutorials to the repository
    Tutorials t1{ "Title 1", "Presenter 1", "www.link1.com", 60, 0, 50 };
    Tutorials t2{ "Title 2", "Presenter 2", "www.link2.com", 45, 30, 30 };
    Tutorials t3{ "Title 3", "Presenter 3", "www.link3.com", 90, 15, 20 };
    repo.addTutorial(t1);
    repo.addTutorial(t2);
    repo.addTutorial(t3);

    DynamicVector<Tutorials> tutorials = service.get_all_tutorials();
    assert(tutorials.getSize() == 3);

    // Check if each tutorial is in the returned list
    assert(tutorials.getElement(0).getTitle() == "Title 1");
    assert(tutorials.getElement(1).getTitle() == "Title 2");
    assert(tutorials.getElement(2).getTitle()== "Title 3");
}
void run_all_tests()
{ 
    test_addTutorialService();
    test_deleteTutorialService();
    //test_getRepo();
    test_getSize();
    test_getTutorialsOfAPresenter();
    test_updateTutorialService();
    testDynamicVector<Tutorials>();
    test_set_title();
    test_get_all_tutorials();
}
