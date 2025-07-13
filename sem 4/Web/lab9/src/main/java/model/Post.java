package model;

import java.nio.file.Path;

public class Post {
    private int id;
    private int nrOfVotes;
    private String photoPath;
    private String userName;

    public Post(int id, int nrOfVotes, String photoPath, String userName) {
        this.id = id;
        this.nrOfVotes = nrOfVotes;
        this.photoPath = photoPath;
        this.userName = userName;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getNrOfVotes() {
        return nrOfVotes;
    }

    public void setNrOfVotes(int nrOfVotes) {
        this.nrOfVotes = nrOfVotes;
    }

    public String getPhotoPath() {
        return photoPath;
    }

    public void setPhotoPath(String photoPath) {
        this.photoPath = photoPath;
    }
    public String getUserName() {
        return userName;
    }
    public void setUserName(String userName) {
        this.userName = userName;
    }
}
