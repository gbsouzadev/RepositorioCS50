import os
import requests
import urllib.parse
import datetime as dt

from flask import redirect, render_template, request, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lastBirthday(month, day):
    thisDate = dt.date.today()
    thisYear = thisDate.year
    thisMonth = thisDate.month
    thisDay = thisDate.day

    if thisMonth < int(month) or (thisMonth == int(month) and thisDay < int(day)):
        year = thisYear-1
        return str(year)
    elif thisMonth > int(month) or (thisMonth == int(month) and thisDay >= int(day)):
        year = thisYear
        return str(year)



def mergeDigits1122(number):

    numberSum = 0
    strNumber = str(number)

    if len(strNumber) == 1 or number == 11 or number == 22:
        return number

    for digit in strNumber:
        numberSum = numberSum + int(digit)
    return mergeDigits1122(numberSum)



def mergeDigits(number):

    numberSum = 0
    strNumber = str(number)

    if len(strNumber) == 1:
        return number

    for digit in strNumber:
        numberSum = numberSum + int(digit)
    return mergeDigits(numberSum)


def piramidBuilder(piramidBuilderList, mergeDigits):
    tmplist = []
    for i in range(len(piramidBuilderList) - 1):
        tmp = mergeDigits(int(piramidBuilderList[i]) + int(piramidBuilderList[i+1]))
        tmplist.append(tmp)
    return tmplist


def findNegativeSequences(lists):

    sequenceList = []
    lists.append("")
    for i in range(len(lists) - 1):
        item = lists[i]
        tmp_list = []
        count = 0

        for nextItem in lists[i:]:
            if nextItem == item:
                tmp_list.append(nextItem)
                count += 1
            if nextItem != item and count >= 3:
                sequenceList.append(tmp_list)
                break
            if nextItem != item and count < 3:
                break
    return sequenceList

def itemCounter(item, firstNameList):
    count = 0
    for element in firstNameList:
        if element == item:
            count += 1
    return count