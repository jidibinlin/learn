from bs4 import BeautifulSoup
from selenium import webdriver
import csv


def fillPostList(postlist, html):
    try:
        soup = BeautifulSoup(html, "html.parser")
        job_all = soup.find_all('div', {"class": "job-primary"})
        for job in job_all:
            position = job.find('span', {"class": "job-name"}).get_text()
            address = job.find('span', {'class': "job-area"}).get_text()
            company = job.find(
                'div', {'class': 'company-text'}).find('h3', {'class': "name"}).get_text()
            salary = job.find('span', {'class': 'red'}).get_text()
            diploma = job.find(
                'div', {'class': 'job-limit clearfix'}).find('p').get_text()[-2:]
            experience = job.find(
                'div', {'class': 'job-limit clearfix'}).find('p').get_text()[:-2]
            labels = job.find('a', {'class': 'false-link'}).get_text()
            postlist.append([position, address, company,
                            salary, diploma, experience, labels])
    except IndexError:
        pass


def main():
    jobinfo = []
    driver = webdriver.Chrome(
        r'./chromedriver')
    url = "https://www.zhipin.com/c101020100/e_102/?query=web%E5%89%8D%E7%AB%AF&page=1&ka=page-1"
    driver.get(url)
    html = driver.page_source
    fillPostList(jobinfo, html)
    # 将jobinfo列表信息写入csv文件
    headers = ["职位", "工作地址", "公司全称", "薪水", "学历", "工作经验", "行业标签"]
    with open('job.csv', 'w', newline='')as f:
        f_csv = csv.writer(f)
        f_csv.writerow(headers)
        f_csv.writerows(jobinfo)
    driver.quit()


main()
