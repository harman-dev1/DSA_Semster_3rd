import pandas as pd
import requests
from bs4 import BeautifulSoup

#Lists for storing data
name_of_course = []
uni_name = []
rating_of_course = []
duration_of_course = []

# Send a GET request to the website
URL = "https://www.coursera.org/courses?query=free"
req = requests.get(URL)
soup = BeautifulSoup(req.content, 'html.parser')
blocks = soup.find_all("div",class_= "cds-ProductCard-content" )
for b in blocks:    
    uni = b.find("p",class_ = "cds-119 cds-ProductCard-partnerNames css-dmxkm1 cds-121").text
    rating = b.find("div",class_ = "cds-CommonCard-ratings").text
    time = b.find("div",class_ = "cds-CommonCard-metadata").text
    course_name = b.find("h1",class_="cds-119 cds-Typography-base css-1xy8ceb cds-121") 
    print(course_name)
    uni_name.append(uni)
    rating_of_course.append(rating)
    duration_of_course.append(time)


# Create a DataFrame from the lists
data_df = pd.DataFrame({
    'Name OF UNIveristy': uni_name,
    'Rating Of Course': rating_of_course,
    'Duration Of Course': duration_of_course
})

#Saving Data Frame To Excel
data_df.to_excel('Coursera.xlsx', index=False)
print("Data saved in Excel File successfully!!!")
