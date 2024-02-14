#include "file format.h"

void HTML::write(const std::vector<Tutorials>& tutorials)
{
    std::ofstream outfile(filename_);
    outfile << "<html><body><table>" << std::endl;
    outfile << "<tr><th>Title</th><th>Presenter</th><th>Link</th><th>Duration (minutes:seconds)</th><th>Likes</th></tr>" << std::endl;
    for (int i = 0; i < tutorials.size(); i++) {
        Tutorials tutorial;
        tutorial = tutorials[i];
        outfile << "<tr><td>" << tutorial.getTitle() << "</td>" << "<td>" << tutorial.getPresenter() << "</td>" << "<td><a href=\"" << tutorial.getLink() << "\">" << tutorial.getLink() << "</a></td>" << "<td>" << tutorial.getDurationMinutes() << ":" << tutorial.getDurationSeconds() << "</td>" << "<td>" << tutorial.getNumberOfLikes() << "</td></tr>" << std::endl;
    }
    outfile << "</table></body></html>" << std::endl;
    outfile.close();
}
void CSV::write(const std::vector<Tutorials>& tutorials)
{
    std::ofstream outfile(filename_);
    for (int i = 0; i < tutorials.size(); i++) {
        Tutorials tutorial;
        tutorial = tutorials[i];
        outfile << tutorial.getTitle() << "," << tutorial.getPresenter() << "," << tutorial.getLink() << "," << tutorial.getDurationMinutes() << "," << tutorial.getDurationSeconds() << "," << tutorial.getNumberOfLikes() << std::endl;
    }
    outfile.close();

}


void TXT::write(const std::vector<Tutorials>& tutorials)
{
    std::ofstream outfile(filename_);
    Tutorials tutorial;
    for (int i = 0; i < tutorials.size(); i++)
    {
        tutorial = tutorials[i];
        outfile << tutorial;
    }
    outfile.close();
}