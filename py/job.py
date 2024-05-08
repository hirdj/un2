from typing import List

class Job:
    def __init__(self, id: str, deadline: int, profit: int):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def schedule_jobs(jobs: List[Job]):
    jobs.sort(key=lambda x: x.profit, reverse=True)

    n = len(jobs)
    slot = [False] * n
    result = [''] * n

    for i in range(n):
        for j in range(min(n, jobs[i].deadline) - 1, -1, -1):
            if not slot[j]:
                result[j] = jobs[i].id
                slot[j] = True
                break

    print("Scheduled Jobs:", " ".join(result))

if __name__ == "__main__":
    jobs = [
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15)
    ]

    schedule_jobs(jobs)
