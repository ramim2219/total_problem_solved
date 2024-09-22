import requests

def get_solved_problems(username):
    url = f"https://codeforces.com/api/user.status?handle={username}"
    response = requests.get(url)
    
    if response.status_code == 200:
        submissions = response.json()["result"]
        solved_problems = set()
        
        for submission in submissions:
            if submission['verdict'] == "OK":
                problem = submission['problem']
                problem_id = f"{problem['contestId']}-{problem['index']}"
                solved_problems.add(problem_id)
        
        return len(solved_problems)
    else:
        print(f"Failed to fetch data from Codeforces API: {response.status_code}")
        return None

if __name__ == "__main__":
    username = "Ramim1234"  # Your Codeforces username
    solved_count = get_solved_problems(username)
    
    if solved_count is not None:
        with open("README.md", "r") as file:
            readme_content = file.readlines()
        
        with open("README.md", "w") as file:
            for line in readme_content:
                if line.startswith("![Codeforces]"):
                    line = f"![Codeforces](https://codeforces.com/profile/{username}) - Total Problems Solved: {solved_count}\n"
                file.write(line)
