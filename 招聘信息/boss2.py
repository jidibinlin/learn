from bs4 import BeautifulSoup
from requests.api import options
from selenium import webdriver
import csv
import time


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


# def main():
#     jobinfo = []
#     driver = webdriver.Chrome(
#         r'./chromedriver')

#     for i in range(1, 100):
#         url = "https://www.zhipin.com/c101020100/e_102/?query=web%E5%89%8D%E7%AB%AF&page="+i+"&ka=page-1"
#         driver.get(url)
#         html = driver.page_source
#         fillPostList(jobinfo, html)
#         # 将jobinfo列表信息写入csv文件
#         headers = ["职位", "工作地址", "公司全称", "薪水", "学历", "工作经验", "行业标签"]
#         with open('job.csv', 'a', newline='')as f:
#             f_csv = csv.writer(f)
#             if(i == 1):
#                 f_csv.writerow(headers)
#             f_csv.writerows(jobinfo)

#     driver.quit()

def main():
    jobinfo = []
    options = webdriver.ChromeOptions()
    options.add_argument(
        'user-agent="Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.0) Opera 12.14"')

    driver = webdriver.Chrome(chrome_options=options)

    for i in range(1, 100):
        url = "https://www.zhipin.com/c101020100/e_102/?query=vue&page=" + \
            str(i)+"&ka=page-"+str(i)
        driver.get(url)
        html = driver.page_source
        fillPostList(jobinfo, html)
        # 将jobinfo列表信息写入csv文件
        headers = ["职位", "工作地址", "公司全称", "薪水", "学历", "工作经验", "行业标签"]
        with open('vue.csv', 'w', newline='')as f:
            f_csv = csv.writer(f)
            if(i == 1):
                f_csv.writerow(headers)
            f_csv.writerows(jobinfo)
        time.sleep(4)

    driver.quit()


main()
