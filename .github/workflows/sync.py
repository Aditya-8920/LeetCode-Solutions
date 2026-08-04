import os
import json
import requests

SESSION = os.environ.get("LEETCODE_SESSION")
if not SESSION:
    print("LEETCODE_SESSION secret missing!")
    exit(1)

headers = {
    "Cookie": f"LEETCODE_SESSION={SESSION};",
    "Referer": "https://leetcode.com",
    "Content-Type": "application/json"
}

query = """
{
  recentSubmissionList(categorySlug: "", limit: 20) {
    title
    titleSlug
    timestamp
    statusDisplay
    lang
  }
}
"""

res = requests.post("https://leetcode.com/graphql", json={"query": query}, headers=headers)
if res.status_code != 200:
    print("Failed to fetch submissions")
    exit(1)

data = res.json().get("data", {}).get("recentSubmissionList", [])

for sub in data:
    if sub["statusDisplay"] == "Accepted":
        title = sub["titleSlug"]
        lang = sub["lang"]
        
        ext_map = {"python3": "py", "cpp": "cpp", "java": "java", "javascript": "js", "c": "c"}
        ext = ext_map.get(lang, "txt")

        folder_name = title
        os.makedirs(folder_name, exist_ok=True)
        
        file_path = os.path.join(folder_name, f"solution.{ext}")
        if not os.path.exists(file_path):
            with open(file_path, "w") as f:
                f.write(f"// Title: {sub['title']}\n// Language: {lang}\n\n// Code synced via GitHub Actions\n")
            print(f"Synced: {title}")
