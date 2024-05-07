<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>AllNews</title>
</head>
<body>
  <div class="header">
    <h2>Welcome to the cool news page</h2>
    <div class="navBar">
      <style>
        .navBar {
          display: flex;
          justify-content: space-between;
          align-items: center;
        }
        .header {
          height: fit-content;
          width: 100%;
          background-color: aquamarine;
          text-align: center;
        }
      </style>
      <a href="mainPage.php">MAIN PAGE</a>
      <a href="loginPage.php">LOGIN</a>
      <a href="seeAllNews.php"><b>SEE ALL</b></a>
      <a href="updateNews.php">UPDATE</a>
      <a href="addNews.php">ADD</a>
    </div>
  </div>

  <div class="filters">
    <div class="categoryFilter">
      <label for="dropDownCategory">Category:</label>
      <select id="dropDownCategory" onchange="updateFilters()"></select>
    </div>
    <div class="datesFilter">
      <div class="date">
        <label for="start">Start date:</label>
        <input type="date" id="start" onchange="updateFilters()" />
      </div>
      <div class="date">
        <label for="end">End date:</label>
        <input type="date" id="end" onchange="updateFilters()" />
      </div>
    </div>
  </div>
  <style>
    .filters {
      display: flex;
      justify-content: space-evenly;
      text-align: center;
      margin-top: 20px;
      margin-bottom: 20px;
    }

    .datesFilter {
      display: flex;
      justify-content: space-around;
    }
    .date {
      margin-left: 10px;
      margin-right: 10px;
    }
    .allNews {
      display: flex;
      justify-content: center;
      align-items: center;
      margin-top: 20px;
    }

    .article {
      border-style: solid;
      border-color: gray;
      border-radius: 20px;
      width: 80%;
      height: fit-content;
      margin-bottom: 20px;
    }
  </style>

  <div class="allNews"></div>

  <script>
    function updateFilters() {
      var selectedCategory = document.getElementById('dropDownCategory').value;
      var startDate = document.getElementById('start').value;
      var endDate = document.getElementById('end').value;

      var xhr = new XMLHttpRequest();
      var url = 'seeAll.php?';
      if (selectedCategory) {
        url += 'category=' + selectedCategory + '&';
      }
      if (startDate && endDate) {
        url += 'startDate=' + startDate + '&endDate=' + endDate;
      }
      xhr.open('GET', url, true);
      xhr.onload = function() {
        if (xhr.status >= 200 && xhr.status < 300) {
          var data = JSON.parse(xhr.responseText);
          renderNews(data);
        } else {
          console.error('Request failed with status', xhr.status);
        }
      };
      xhr.send();
    }

    function renderNews(data) {
      var allNewsDiv = document.querySelector('.allNews');
      allNewsDiv.innerHTML = ''; 
      data.forEach(function(news) {
        var articleDiv = document.createElement('div');
        articleDiv.classList.add('article');

        var titleHeading = document.createElement('h3');
        titleHeading.textContent = news.title;

        var detailsDiv = document.createElement('div');
        detailsDiv.classList.add('details');

        var authorDiv = document.createElement('div');
        authorDiv.textContent = 'Author: ' + news.producer;

        var dateDiv = document.createElement('div');
        dateDiv.textContent = 'Date: ' + news.dateOfNews;

        var textParagraph = document.createElement('p');
        textParagraph.textContent = news.textNews;

        detailsDiv.appendChild(authorDiv);
        detailsDiv.appendChild(dateDiv);

        articleDiv.appendChild(titleHeading);
        articleDiv.appendChild(detailsDiv);
        articleDiv.appendChild(textParagraph);

        allNewsDiv.appendChild(articleDiv);
      });
    }

    window.onload = function() {
      var xhr = new XMLHttpRequest();
      xhr.open('GET', 'getCategories.php', true);
      xhr.onload = function() {
        if (xhr.status >= 200 && xhr.status < 300) {
          var categories = JSON.parse(xhr.responseText);
          var dropDownCategory = document.getElementById('dropDownCategory');
          categories.forEach(function(category) {
            var option = document.createElement('option');
            option.value = category;
            option.textContent = category;
            dropDownCategory.appendChild(option);
          });
          updateFilters(); 
        } else {
          console.error('Failed to load categories', xhr.status);
        }
      };
      xhr.send();
    };
  </script>
</body>
</html>
