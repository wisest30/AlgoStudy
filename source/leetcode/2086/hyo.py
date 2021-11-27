class Solution:
    def minimumBuckets(self, street: str) -> int:
        if len(street) == 1 :
            return -1 if street == 'H' else 0
        elif street.startswith("HH") or street.endswith("HH") or "HHH" in street:
            return -1
        else :
            return street.count('H') - street.count('H.H')
