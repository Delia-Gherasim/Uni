#include "tests.h"
#include <assert.h>

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

    std::vector<Tutorials> tutorials = service.getTutorialsOfAPresenter("presenter1");
    // assert(tutorials.size() == 2);

}
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

    std::vector<Tutorials> tutorials = service.get_all_tutorials();
    assert(tutorials.size() == 3);

    // Check if each tutorial is in the returned list
    assert(tutorials[0].getTitle() == "Title 1");
    assert(tutorials[1].getTitle() == "Title 2");
    assert(tutorials[2].getTitle() == "Title 3");

}
void test_tutorials_class()
{
    Tutorials tutorial;

    // Test getTitle() and setTitle()
    tutorial.setTitle("Introduction to C++");
    assert(tutorial.getTitle() == "Introduction to C++");

    // Test getPresenter() and setPresenter()
    tutorial.setPresenter("John Smith");
    assert(tutorial.getPresenter() == "John Smith");

    // Test getLink() and setLink()
    tutorial.setLink("https://www.youtube.com/watch?v=123456");
    assert(tutorial.getLink() == "https://www.youtube.com/watch?v=123456");

    // Test getDurationMinutes() and setDurationMinutes()
    tutorial.setDurationMinutes(60);
    assert(tutorial.getDurationMinutes() == 60);

    // Test getDurationSeconds() and setDurationSeconds()
    tutorial.setDurationSeconds(30);
    assert(tutorial.getDurationSeconds() == 30);

    // Test getNumberOfLikes() and setNumberOfLikes()
    tutorial.setNumberOfLikes(1000);
    assert(tutorial.getNumberOfLikes() == 1000);
}
//
//void test_save_functions() {
//    // create some test data
//    std::vector<Tutorials> tutorials = {
//        {"Tutorial 1", "Presenter 1", "http://tutorial1.com", 10, 30, 100},
//        {"Tutorial 2", "Presenter 2", "http://tutorial2.com", 5, 45, 50},
//        {"Tutorial 3", "Presenter 3", "http://tutorial3.com", 20, 0, 200},
//    };
//
//    // create CSV object and test write function
//    {
//        CSV csv("test.csv");
//        csv.write(tutorials);
//
//        // open the file and check if it is not empty
//        std::ifstream file("test.csv");
//        assert(file.good());
//        assert(file.peek() != std::ifstream::traits_type::eof());
//    }
//
//    // create HTML object and test write function
//    {
//        HTML html("test.html");
//        html.write(tutorials);
//
//        // open the file and check if it is not empty
//        std::ifstream file("test.html");
//        assert(file.good());
//        assert(file.peek() != std::ifstream::traits_type::eof());
//    }
//}
void test_tutorial_validator() {
    TutorialValidator validator;

    // create a valid tutorial
    Tutorials valid_tutorial = { "Valid Tutorial", "Valid Presenter", "http://validtutorial.com", 10, 30, 100 };
    assert(validator.validate(valid_tutorial) == true);

    // test with an empty title
    Tutorials empty_title_tutorial = { "", "Presenter", "http://validtutorial.com", 10, 30, 100 };
    assert(validator.validate(empty_title_tutorial) == false);

    // test with an empty presenter
    Tutorials empty_presenter_tutorial = { "Valid Tutorial", "", "http://validtutorial.com", 10, 30, 100 };
    assert(validator.validate(empty_presenter_tutorial) == false);

    // test with an empty link
    Tutorials empty_link_tutorial = { "Valid Tutorial", "Presenter", "", 10, 30, 100 };
    assert(validator.validate(empty_link_tutorial) == false);

    // test with negative duration minutes
    Tutorials negative_minutes_tutorial = { "Valid Tutorial", "Presenter", "http://validtutorial.com", -1, 30, 100 };
    assert(validator.validate(negative_minutes_tutorial) == false);

    // test with negative duration seconds
    Tutorials negative_seconds_tutorial = { "Valid Tutorial", "Presenter", "http://validtutorial.com", 10, -1, 100 };
    assert(validator.validate(negative_seconds_tutorial) == false);

    // test with duration seconds greater than or equal to 60
    Tutorials invalid_seconds_tutorial = { "Valid Tutorial", "Presenter", "http://validtutorial.com", 10, 60, 100 };
    assert(validator.validate(invalid_seconds_tutorial) == false);

    // test with negative number of likes
    Tutorials negative_likes_tutorial = { "Valid Tutorial", "Presenter", "http://validtutorial.com", 10, 30, -1 };
    assert(validator.validate(negative_likes_tutorial) == false);
}
void test_file_format() {
    // create some test data
    std::vector<Tutorials> tutorials = {
        {"Tutorial 1", "Presenter 1", "http://tutorial1.com", 10, 30, 100},
        {"Tutorial 2", "Presenter 2", "http://tutorial2.com", 5, 45, 50},
        {"Tutorial 3", "Presenter 3", "http://tutorial3.com", 20, 0, 200},
    };

    // create CSV object and test write function
    {
        CSV csv;
        csv.set_filename("test.csv");
        csv.write(tutorials);
    }

    // create HTML object and test write function
    {
        HTML html;
        html.set_filename("test.html");
        html.write(tutorials);
    }
}

void run_all_tests()
{
    //test_save_functions();
    test_file_format();
    test_tutorial_validator();
    test_tutorials_class();
    test_addTutorialService();
    test_deleteTutorialService();
    test_getSize();
    test_getTutorialsOfAPresenter();
    test_updateTutorialService();

    test_set_title();
    test_get_all_tutorials();
}
