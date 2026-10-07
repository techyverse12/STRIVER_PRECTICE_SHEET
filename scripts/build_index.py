"""Rebuild README.md from the LeetSync solution folders.

Each folder looks like "<id>-<slug>/" and holds a README.md (problem statement
written by LeetSync, including a Difficulty badge) plus the solution file.
"""
import html
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parent.parent
EXT_LANG = {".cpp": "C++", ".sql": "SQL", ".py": "Python", ".java": "Java", ".js": "JavaScript"}
ORDER = ["Easy", "Medium", "Hard"]


def read_problem(folder: pathlib.Path):
    readme = folder / "README.md"
    if not readme.exists():
        return None
    head = readme.read_text(encoding="utf-8", errors="ignore")[:1500]
    title = re.search(r'<a href="(https://leetcode\.com/problems/[^"]+)">([^<]+)</a>', head)
    level = re.search(r"Difficulty-(Easy|Medium|Hard)", head)
    if not title or not level:
        return None
    langs = sorted({EXT_LANG[p.suffix] for p in folder.iterdir() if p.suffix in EXT_LANG})
    return {
        "folder": folder.name,
        "title": html.unescape(title.group(2)),
        "url": title.group(1),
        "level": level.group(1),
        "langs": " · ".join(langs) or "pending",
    }


def main():
    problems = [p for d in sorted(ROOT.iterdir()) if d.is_dir() and not d.name.startswith(".")
                and re.match(r"^\d+-", d.name) and (p := read_problem(d))]
    problems.sort(key=lambda p: int(p["folder"].split("-", 1)[0]))
    counts = {lvl: sum(p["level"] == lvl for p in problems) for lvl in ORDER}

    lines = [
        "# DSA practice",
        "",
        "My LeetCode solutions, mostly in C++, following Striver's A2Z DSA sheet. "
        "Every accepted submission is pushed here automatically by "
        "[LeetSync](https://github.com/LeetSync/LeetSync), and this index rebuilds itself on each push.",
        "",
        f"**{len(problems)} problems here** · {counts['Easy']} easy · {counts['Medium']} medium · "
        f"{counts['Hard']} hard",
        "",
        "Full profile: [leetcode.com/u/Kavaygoyal493](https://leetcode.com/u/Kavaygoyal493/)",
        "",
    ]
    for lvl in ORDER:
        group = [p for p in problems if p["level"] == lvl]
        if not group:
            continue
        lines += [f"## {lvl}", "", "| Problem | Solution | Language |", "|---|---|---|"]
        for p in group:
            lines.append(f"| [{p['title']}]({p['url']}) | [code](./{p['folder']}/) | {p['langs']} |")
        lines.append("")

    (ROOT / "README.md").write_text("\n".join(lines), encoding="utf-8")
    print(f"Indexed {len(problems)} problems")


if __name__ == "__main__":
    main()
